	.include "MPlayDef.s"

	.equ	se_w029_grp, voicegroup_869D6F4
	.equ	se_w029_pri, 4
	.equ	se_w029_rev, reverb_set+50
	.equ	se_w029_mvl, 127
	.equ	se_w029_key, 0
	.equ	se_w029_tbs, 1
	.equ	se_w029_exg, 0
	.equ	se_w029_cmp, 1

	.section .rodata
	.global	se_w029
	.align	2

@********************** Track  1 **********************@

se_w029_1:
	.byte	KEYSH , se_w029_key+0
	.byte	TEMPO , 150*se_w029_tbs/2
	.byte		VOICE , 2
	.byte		BENDR , 12
	.byte		PAN   , c_v+0
	.byte		VOL   , 25*se_w029_mvl/mxv
	.byte		BEND  , c_v-48
	.byte		N07   , Cn1 , v127
	.byte	W01
	.byte		VOL   , 41*se_w029_mvl/mxv
	.byte		BEND  , c_v-31
	.byte	W01
	.byte		PAN   , c_v+7
	.byte		VOL   , 57*se_w029_mvl/mxv
	.byte		BEND  , c_v-16
	.byte	W01
	.byte		VOL   , 79*se_w029_mvl/mxv
	.byte		BEND  , c_v+0
	.byte	W01
	.byte		PAN   , c_v+11
	.byte		VOL   , 110*se_w029_mvl/mxv
	.byte		BEND  , c_v+14
	.byte	W02
	.byte		        c_v+32
	.byte	W01
	.byte		PAN   , c_v+14
	.byte	W01
	.byte		VOL   , 25*se_w029_mvl/mxv
	.byte		BEND  , c_v-48
	.byte		N07   , Dn1 
	.byte	W01
	.byte		PAN   , c_v+19
	.byte		VOL   , 41*se_w029_mvl/mxv
	.byte		BEND  , c_v-31
	.byte	W01
	.byte		VOL   , 57*se_w029_mvl/mxv
	.byte		BEND  , c_v-16
	.byte	W02
	.byte		PAN   , c_v+0
	.byte		VOL   , 79*se_w029_mvl/mxv
	.byte		BEND  , c_v+0
	.byte	W01
	.byte		VOL   , 110*se_w029_mvl/mxv
	.byte		BEND  , c_v+14
	.byte	W01
	.byte		PAN   , c_v-8
	.byte		BEND  , c_v+32
	.byte	W02
	.byte		PAN   , c_v-11
	.byte	W03
	.byte		        c_v-15
	.byte	W05
	.byte		VOL   , 110*se_w029_mvl/mxv
	.byte	FINE

@******************************************************@
	.align	2

se_w029:
	.byte	1	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_w029_pri	@ Priority
	.byte	se_w029_rev	@ Reverb.

	.word	se_w029_grp

	.word	se_w029_1

	.end
