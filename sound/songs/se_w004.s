	.include "MPlayDef.s"

	.equ	se_w004_grp, voicegroup_869D6F4
	.equ	se_w004_pri, 4
	.equ	se_w004_rev, reverb_set+50
	.equ	se_w004_mvl, 127
	.equ	se_w004_key, 0
	.equ	se_w004_tbs, 1
	.equ	se_w004_exg, 0
	.equ	se_w004_cmp, 1

	.section .rodata
	.global	se_w004
	.align	2

@********************** Track  1 **********************@

se_w004_1:
	.byte	KEYSH , se_w004_key+0
	.byte	TEMPO , 150*se_w004_tbs/2
	.byte		VOICE , 6
	.byte		VOL   , 120*se_w004_mvl/mxv
	.byte		BENDR , 12
	.byte		PAN   , c_v+0
	.byte		BEND  , c_v+0
	.byte		N03   , Cn3 , v127
	.byte	W01
	.byte		PAN   , c_v-10
	.byte		BEND  , c_v-27
	.byte	W01
	.byte		PAN   , c_v+8
	.byte		BEND  , c_v-47
	.byte	W01
	.byte		        c_v-64
	.byte	W01
	.byte		PAN   , c_v+0
	.byte		BEND  , c_v+1
	.byte		N02   , Dn3 , v084
	.byte	W02
	.byte		BEND  , c_v-32
	.byte	W18
	.byte	FINE

@********************** Track  2 **********************@

se_w004_2:
	.byte	KEYSH , se_w004_key+0
	.byte		VOICE , 5
	.byte		XCMD  , xIECV , 10
	.byte		        xIECL , 8
	.byte		VOL   , 120*se_w004_mvl/mxv
	.byte		PAN   , c_v+9
	.byte		N03   , An2 , v052
	.byte	W04
	.byte		N02   
	.byte	W02
	.byte		PAN   , c_v-8
	.byte	W18
	.byte	FINE

@******************************************************@
	.align	2

se_w004:
	.byte	2	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_w004_pri	@ Priority
	.byte	se_w004_rev	@ Reverb.

	.word	se_w004_grp

	.word	se_w004_1
	.word	se_w004_2

	.end
