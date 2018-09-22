	.include "MPlayDef.s"

	.equ	se_w208_grp, voicegroup128
	.equ	se_w208_pri, 4
	.equ	se_w208_rev, reverb_set+50
	.equ	se_w208_mvl, 127
	.equ	se_w208_key, 0
	.equ	se_w208_tbs, 1
	.equ	se_w208_exg, 0
	.equ	se_w208_cmp, 1

	.section .rodata
	.global	se_w208
	.align	2

@********************** Track  1 **********************@

se_w208_1:
	.byte	KEYSH , se_w208_key+0
	.byte	TEMPO , 180*se_w208_tbs/2
	.byte		VOICE , 16
	.byte		BENDR , 12
	.byte		PAN   , c_v+0
	.byte		VOL   , 100*se_w208_mvl/mxv
	.byte		BEND  , c_v+0
	.byte		N06   , An6 , v100
	.byte	W01
	.byte		BEND  , c_v-11
	.byte	W01
	.byte		PAN   , c_v+5
	.byte		VOL   , 90*se_w208_mvl/mxv
	.byte		BEND  , c_v-20
	.byte	W01
	.byte		PAN   , c_v-6
	.byte		VOL   , 77*se_w208_mvl/mxv
	.byte		BEND  , c_v-37
	.byte	W01
	.byte		PAN   , c_v+0
	.byte		VOL   , 37*se_w208_mvl/mxv
	.byte		BEND  , c_v-47
	.byte	W02
	.byte		N02   , An6 , v056
	.byte	W01
	.byte		PAN   , c_v+5
	.byte	W01
	.byte		        c_v-6
	.byte		VOL   , 100*se_w208_mvl/mxv
	.byte		BEND  , c_v+0
	.byte		N06   , An6 , v100
	.byte	W01
	.byte		PAN   , c_v+8
	.byte		BEND  , c_v-11
	.byte	W01
	.byte		PAN   , c_v-10
	.byte		VOL   , 90*se_w208_mvl/mxv
	.byte		BEND  , c_v-20
	.byte	W02
	.byte		PAN   , c_v+1
	.byte		VOL   , 77*se_w208_mvl/mxv
	.byte		BEND  , c_v-37
	.byte	W01
	.byte		PAN   , c_v+5
	.byte		VOL   , 37*se_w208_mvl/mxv
	.byte		BEND  , c_v-47
	.byte	W01
	.byte		PAN   , c_v-6
	.byte		N02   , An6 , v056
	.byte	W01
	.byte		PAN   , c_v+8
	.byte	W01
	.byte		        c_v-10
	.byte		VOL   , 100*se_w208_mvl/mxv
	.byte		BEND  , c_v+0
	.byte		N06   , An6 , v072
	.byte	W02
	.byte		PAN   , c_v+0
	.byte		BEND  , c_v-11
	.byte	W01
	.byte		PAN   , c_v+5
	.byte		VOL   , 90*se_w208_mvl/mxv
	.byte		BEND  , c_v-20
	.byte	W01
	.byte		PAN   , c_v-6
	.byte		VOL   , 77*se_w208_mvl/mxv
	.byte		BEND  , c_v-37
	.byte	W01
	.byte		PAN   , c_v+8
	.byte		VOL   , 37*se_w208_mvl/mxv
	.byte		BEND  , c_v-47
	.byte	W01
	.byte		PAN   , c_v-10
	.byte	W02
	.byte	W06
	.byte	FINE

@********************** Track  2 **********************@

se_w208_2:
	.byte	KEYSH , se_w208_key+0
	.byte		VOICE , 53
	.byte		VOL   , 100*se_w208_mvl/mxv
	.byte	W02
	.byte		N06   , Fs6 , v040
	.byte	W04
	.byte	W04
	.byte		N06   
	.byte	W02
	.byte	W06
	.byte	W01
	.byte		        Fs6 , v032
	.byte	W05
	.byte	W06
	.byte	FINE

@******************************************************@
	.align	2

se_w208:
	.byte	2	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_w208_pri	@ Priority
	.byte	se_w208_rev	@ Reverb.

	.word	se_w208_grp

	.word	se_w208_1
	.word	se_w208_2

	.end
