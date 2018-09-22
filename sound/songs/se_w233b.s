	.include "MPlayDef.s"

	.equ	se_w233b_grp, voicegroup128
	.equ	se_w233b_pri, 4
	.equ	se_w233b_rev, reverb_set+50
	.equ	se_w233b_mvl, 127
	.equ	se_w233b_key, 0
	.equ	se_w233b_tbs, 1
	.equ	se_w233b_exg, 0
	.equ	se_w233b_cmp, 1

	.section .rodata
	.global	se_w233b
	.align	2

@********************** Track  1 **********************@

se_w233b_1:
	.byte	KEYSH , se_w233b_key+0
	.byte	TEMPO , 220*se_w233b_tbs/2
	.byte		VOICE , 6
	.byte		VOL   , 110*se_w233b_mvl/mxv
	.byte		BENDR , 12
	.byte		PAN   , c_v+0
	.byte		BEND  , c_v+0
	.byte		N06   , Cn3 , v127
	.byte	W01
	.byte		BEND  , c_v-9
	.byte	W01
	.byte		        c_v-21
	.byte	W01
	.byte		PAN   , c_v-6
	.byte		BEND  , c_v-40
	.byte	W01
	.byte		        c_v-64
	.byte	W02
	.byte		PAN   , c_v+0
	.byte		BEND  , c_v+0
	.byte		N06   , En3 
	.byte	W01
	.byte		BEND  , c_v-9
	.byte	W01
	.byte		        c_v-21
	.byte	W01
	.byte		PAN   , c_v+7
	.byte		BEND  , c_v-40
	.byte	W01
	.byte		        c_v-64
	.byte	W02
	.byte		PAN   , c_v+0
	.byte		BEND  , c_v+0
	.byte		N09   , An2 
	.byte	W01
	.byte		BEND  , c_v-9
	.byte	W01
	.byte		        c_v-19
	.byte	W01
	.byte		        c_v-29
	.byte	W01
	.byte		VOL   , 86*se_w233b_mvl/mxv
	.byte		BEND  , c_v-39
	.byte	W02
	.byte		VOL   , 69*se_w233b_mvl/mxv
	.byte		BEND  , c_v-45
	.byte	W01
	.byte		VOL   , 53*se_w233b_mvl/mxv
	.byte		BEND  , c_v-56
	.byte	W01
	.byte		VOL   , 20*se_w233b_mvl/mxv
	.byte		BEND  , c_v-64
	.byte	W04
	.byte		        c_v-64
	.byte	FINE

@********************** Track  2 **********************@

se_w233b_2:
	.byte	KEYSH , se_w233b_key+0
	.byte		VOICE , 5
	.byte		XCMD  , xIECV , 10
	.byte		        xIECL , 8
	.byte		VOL   , 110*se_w233b_mvl/mxv
	.byte		PAN   , c_v+9
	.byte		N03   , Gs2 , v052
	.byte	W06
	.byte		PAN   , c_v-7
	.byte		N03   
	.byte	W06
	.byte		PAN   , c_v+0
	.byte		N03   
	.byte	W12
	.byte	FINE

@******************************************************@
	.align	2

se_w233b:
	.byte	2	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_w233b_pri	@ Priority
	.byte	se_w233b_rev	@ Reverb.

	.word	se_w233b_grp

	.word	se_w233b_1
	.word	se_w233b_2

	.end
