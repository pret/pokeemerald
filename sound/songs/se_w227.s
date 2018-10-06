	.include "MPlayDef.s"

	.equ	se_w227_grp, voicegroup128
	.equ	se_w227_pri, 4
	.equ	se_w227_rev, reverb_set+50
	.equ	se_w227_mvl, 127
	.equ	se_w227_key, 0
	.equ	se_w227_tbs, 1
	.equ	se_w227_exg, 0
	.equ	se_w227_cmp, 1

	.section .rodata
	.global	se_w227
	.align	2

@********************** Track  1 **********************@

se_w227_1:
	.byte	KEYSH , se_w227_key+0
	.byte	TEMPO , 150*se_w227_tbs/2
	.byte		VOICE , 59
	.byte		BENDR , 12
	.byte		VOL   , 110*se_w227_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		BEND  , c_v+0
	.byte		N06   , En3 , v127
	.byte	W01
	.byte		PAN   , c_v+8
	.byte	W01
	.byte		        c_v-9
	.byte	W01
	.byte		        c_v+14
	.byte	W01
	.byte		        c_v-10
	.byte	W02
	.byte		        c_v+0
	.byte		N03   , An3 , v048
	.byte	W01
	.byte		PAN   , c_v+16
	.byte	W01
	.byte		        c_v-16
	.byte	W04
	.byte	FINE

@******************************************************@
	.align	2

se_w227:
	.byte	1	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_w227_pri	@ Priority
	.byte	se_w227_rev	@ Reverb.

	.word	se_w227_grp

	.word	se_w227_1

	.end
