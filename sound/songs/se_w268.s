	.include "MPlayDef.s"

	.equ	se_w268_grp, voicegroup128
	.equ	se_w268_pri, 4
	.equ	se_w268_rev, reverb_set+50
	.equ	se_w268_mvl, 127
	.equ	se_w268_key, 0
	.equ	se_w268_tbs, 1
	.equ	se_w268_exg, 0
	.equ	se_w268_cmp, 1

	.section .rodata
	.global	se_w268
	.align	2

@********************** Track  1 **********************@

se_w268_1:
	.byte	KEYSH , se_w268_key+0
	.byte	TEMPO , 150*se_w268_tbs/2
	.byte		VOICE , 18
	.byte		BENDR , 12
	.byte		PAN   , c_v+0
	.byte		VOL   , 34*se_w268_mvl/mxv
	.byte		BEND  , c_v+0
	.byte		N66   , Cn5 , v127
	.byte	W01
	.byte		PAN   , c_v-2
	.byte	W01
	.byte		VOL   , 43*se_w268_mvl/mxv
	.byte		PAN   , c_v+0
	.byte	W01
	.byte		        c_v+2
	.byte		BEND  , c_v-2
	.byte	W01
	.byte		VOL   , 58*se_w268_mvl/mxv
	.byte		PAN   , c_v+0
	.byte	W02
	.byte		        c_v-2
	.byte	W01
	.byte		VOL   , 70*se_w268_mvl/mxv
	.byte		PAN   , c_v-4
	.byte		BEND  , c_v-4
	.byte	W01
	.byte		PAN   , c_v-2
	.byte	W01
	.byte		VOL   , 76*se_w268_mvl/mxv
	.byte		PAN   , c_v+0
	.byte	W01
	.byte		        c_v+2
	.byte		BEND  , c_v-6
	.byte	W02
	.byte		VOL   , 90*se_w268_mvl/mxv
	.byte		PAN   , c_v+4
	.byte	W01
	.byte		        c_v+2
	.byte	W01
	.byte		        c_v+0
	.byte		BEND  , c_v-8
	.byte	W01
	.byte		PAN   , c_v+0
	.byte	W01
	.byte		        c_v-2
	.byte	W02
	.byte		        c_v+0
	.byte		BEND  , c_v-13
	.byte	W01
	.byte		PAN   , c_v+2
	.byte	W01
	.byte		        c_v+0
	.byte	W01
	.byte		        c_v-2
	.byte		BEND  , c_v-15
	.byte	W01
	.byte		PAN   , c_v-4
	.byte	W02
	.byte		        c_v-2
	.byte	W01
	.byte		        c_v+0
	.byte		BEND  , c_v-19
	.byte	W01
	.byte		PAN   , c_v+2
	.byte	W01
	.byte		        c_v+4
	.byte		BEND  , c_v-22
	.byte	W01
	.byte		PAN   , c_v+2
	.byte	W02
	.byte		        c_v+0
	.byte		BEND  , c_v-19
	.byte	W01
	.byte		PAN   , c_v+0
	.byte	W01
	.byte		        c_v-2
	.byte		BEND  , c_v-17
	.byte	W01
	.byte		PAN   , c_v+0
	.byte	W01
	.byte		        c_v+2
	.byte	W02
	.byte		        c_v+0
	.byte		BEND  , c_v-19
	.byte	W01
	.byte		PAN   , c_v-2
	.byte	W01
	.byte		        c_v-4
	.byte	W01
	.byte		        c_v-2
	.byte		BEND  , c_v-22
	.byte	W01
	.byte		PAN   , c_v+0
	.byte	W02
	.byte		        c_v+2
	.byte		BEND  , c_v-28
	.byte	W01
	.byte		PAN   , c_v+4
	.byte		BEND  , c_v-24
	.byte	W01
	.byte		PAN   , c_v+2
	.byte	W01
	.byte		VOL   , 84*se_w268_mvl/mxv
	.byte		PAN   , c_v+0
	.byte	W01
	.byte		        c_v+0
	.byte	W02
	.byte		        c_v-2
	.byte	W01
	.byte		VOL   , 78*se_w268_mvl/mxv
	.byte		PAN   , c_v+0
	.byte	W01
	.byte		        c_v+2
	.byte		BEND  , c_v-27
	.byte	W01
	.byte		PAN   , c_v+0
	.byte	W01
	.byte		VOL   , 70*se_w268_mvl/mxv
	.byte		PAN   , c_v-2
	.byte	W02
	.byte		        c_v-4
	.byte	W01
	.byte		VOL   , 55*se_w268_mvl/mxv
	.byte		PAN   , c_v-2
	.byte		BEND  , c_v-29
	.byte	W01
	.byte		PAN   , c_v+0
	.byte	W01
	.byte		VOL   , 46*se_w268_mvl/mxv
	.byte		PAN   , c_v+2
	.byte	W01
	.byte		        c_v+4
	.byte		BEND  , c_v-31
	.byte	W02
	.byte		VOL   , 36*se_w268_mvl/mxv
	.byte		PAN   , c_v+2
	.byte	W01
	.byte		        c_v+0
	.byte	W01
	.byte		VOL   , 24*se_w268_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		BEND  , c_v-36
	.byte	W01
	.byte		PAN   , c_v-2
	.byte	W01
	.byte		VOL   , 13*se_w268_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		BEND  , c_v-42
	.byte	W02
	.byte		VOL   , 5*se_w268_mvl/mxv
	.byte		PAN   , c_v+2
	.byte	W06
	.byte	FINE

@******************************************************@
	.align	2

se_w268:
	.byte	1	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_w268_pri	@ Priority
	.byte	se_w268_rev	@ Reverb.

	.word	se_w268_grp

	.word	se_w268_1

	.end
