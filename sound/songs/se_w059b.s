	.include "MPlayDef.s"

	.equ	se_w059b_grp, voicegroup128
	.equ	se_w059b_pri, 4
	.equ	se_w059b_rev, reverb_set+50
	.equ	se_w059b_mvl, 127
	.equ	se_w059b_key, 0
	.equ	se_w059b_tbs, 1
	.equ	se_w059b_exg, 0
	.equ	se_w059b_cmp, 1

	.section .rodata
	.global	se_w059b
	.align	2

@********************** Track  1 **********************@

se_w059b_1:
	.byte	KEYSH , se_w059b_key+0
	.byte	TEMPO , 150*se_w059b_tbs/2
	.byte		VOICE , 22
	.byte		BENDR , 12
	.byte		PAN   , c_v+0
	.byte		VOL   , 110*se_w059b_mvl/mxv
	.byte		BEND  , c_v+0
	.byte		N24   , Gn3 , v108
	.byte	W02
	.byte		PAN   , c_v-19
	.byte	W04
	.byte		        c_v+0
	.byte	W01
	.byte		VOL   , 97*se_w059b_mvl/mxv
	.byte	W01
	.byte		PAN   , c_v+16
	.byte	W01
	.byte		VOL   , 84*se_w059b_mvl/mxv
	.byte	W03
	.byte		        76*se_w059b_mvl/mxv
	.byte		PAN   , c_v+2
	.byte	W02
	.byte		VOL   , 55*se_w059b_mvl/mxv
	.byte		PAN   , c_v-8
	.byte	W02
	.byte		VOL   , 39*se_w059b_mvl/mxv
	.byte	W02
	.byte		PAN   , c_v+0
	.byte	W01
	.byte		VOL   , 25*se_w059b_mvl/mxv
	.byte	W01
	.byte		PAN   , c_v+8
	.byte	W01
	.byte		VOL   , 13*se_w059b_mvl/mxv
	.byte	W03
	.byte		        7*se_w059b_mvl/mxv
	.byte		PAN   , c_v+0
	.byte	W24
	.byte	FINE

@******************************************************@
	.align	2

se_w059b:
	.byte	1	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_w059b_pri	@ Priority
	.byte	se_w059b_rev	@ Reverb.

	.word	se_w059b_grp

	.word	se_w059b_1

	.end
