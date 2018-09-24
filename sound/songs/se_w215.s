	.include "MPlayDef.s"

	.equ	se_w215_grp, voicegroup128
	.equ	se_w215_pri, 4
	.equ	se_w215_rev, reverb_set+50
	.equ	se_w215_mvl, 127
	.equ	se_w215_key, 0
	.equ	se_w215_tbs, 1
	.equ	se_w215_exg, 0
	.equ	se_w215_cmp, 1

	.section .rodata
	.global	se_w215
	.align	2

@********************** Track  1 **********************@

se_w215_1:
	.byte	KEYSH , se_w215_key+0
	.byte	TEMPO , 150*se_w215_tbs/2
	.byte		VOICE , 51
	.byte		BENDR , 2
	.byte		PAN   , c_v+0
	.byte		VOL   , 90*se_w215_mvl/mxv
	.byte		BEND  , c_v+4
	.byte		N03   , As5 , v100
	.byte	W01
	.byte		PAN   , c_v-13
	.byte	W01
	.byte		        c_v+11
	.byte	W01
	.byte		        c_v+1
	.byte		N01   , An5 
	.byte	W01
	.byte		MOD   , 7
	.byte		N18   , Bn5 
	.byte	W02
	.byte		PAN   , c_v+11
	.byte	W01
	.byte		MOD   , 0
	.byte		PAN   , c_v-14
	.byte	W01
	.byte		        c_v+11
	.byte	W01
	.byte		        c_v-13
	.byte	W01
	.byte		        c_v+11
	.byte	W02
	.byte		        c_v-14
	.byte	W01
	.byte		        c_v+11
	.byte	W01
	.byte		        c_v-13
	.byte	W01
	.byte		        c_v+11
	.byte	W01
	.byte		MOD   , 7
	.byte		PAN   , c_v-14
	.byte	W02
	.byte		        c_v+11
	.byte	W01
	.byte		        c_v-14
	.byte	W01
	.byte		        c_v+11
	.byte	W01
	.byte		        c_v-13
	.byte	W03
	.byte	FINE

@******************************************************@
	.align	2

se_w215:
	.byte	1	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_w215_pri	@ Priority
	.byte	se_w215_rev	@ Reverb.

	.word	se_w215_grp

	.word	se_w215_1

	.end
