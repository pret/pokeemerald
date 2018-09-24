	.include "MPlayDef.s"

	.equ	se_w109_grp, voicegroup128
	.equ	se_w109_pri, 4
	.equ	se_w109_rev, reverb_set+50
	.equ	se_w109_mvl, 127
	.equ	se_w109_key, 0
	.equ	se_w109_tbs, 1
	.equ	se_w109_exg, 0
	.equ	se_w109_cmp, 1

	.section .rodata
	.global	se_w109
	.align	2

@********************** Track  1 **********************@

se_w109_1:
	.byte	KEYSH , se_w109_key+0
	.byte	TEMPO , 220*se_w109_tbs/2
	.byte		VOICE , 52
	.byte		VOL   , 127*se_w109_mvl/mxv
	.byte		BENDR , 12
	.byte		PAN   , c_v+0
	.byte		BEND  , c_v+0
	.byte		N03   , As3 , v120
	.byte	W01
	.byte		BEND  , c_v-8
	.byte	W01
	.byte		        c_v-16
	.byte	W01
	.byte		        c_v-1
	.byte		N12   , As2 , v127
	.byte	W03
	.byte		PAN   , c_v+4
	.byte		BEND  , c_v+8
	.byte	W02
	.byte		PAN   , c_v-4
	.byte		BEND  , c_v+11
	.byte	W01
	.byte		        c_v+18
	.byte	W01
	.byte		PAN   , c_v+10
	.byte		BEND  , c_v+28
	.byte	W02
	.byte		        c_v+35
	.byte	W01
	.byte		PAN   , c_v-10
	.byte	W02
	.byte		        c_v+0
	.byte		BEND  , c_v+0
	.byte		N03   , As3 , v108
	.byte	W01
	.byte		BEND  , c_v-8
	.byte	W02
	.byte		        c_v-17
	.byte	W01
	.byte		        c_v-1
	.byte		N12   , As2 
	.byte	W02
	.byte		PAN   , c_v+4
	.byte		BEND  , c_v+8
	.byte	W03
	.byte		PAN   , c_v-4
	.byte		BEND  , c_v+11
	.byte	W01
	.byte		        c_v+18
	.byte	W01
	.byte		PAN   , c_v+10
	.byte		BEND  , c_v+28
	.byte	W01
	.byte		        c_v+35
	.byte	W01
	.byte		PAN   , c_v-10
	.byte	W03
	.byte		        c_v+0
	.byte		BEND  , c_v+0
	.byte		N03   , As3 , v072
	.byte	W01
	.byte		BEND  , c_v-8
	.byte	W01
	.byte		        c_v-16
	.byte	W01
	.byte		        c_v-1
	.byte		N12   , As2 
	.byte	W03
	.byte		PAN   , c_v+4
	.byte		BEND  , c_v+8
	.byte	W02
	.byte		PAN   , c_v-4
	.byte		BEND  , c_v+11
	.byte	W01
	.byte		        c_v+18
	.byte	W02
	.byte		PAN   , c_v+10
	.byte		BEND  , c_v+28
	.byte	W01
	.byte		        c_v+35
	.byte	W01
	.byte		PAN   , c_v-10
	.byte	W04
	.byte	FINE

@******************************************************@
	.align	2

se_w109:
	.byte	1	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_w109_pri	@ Priority
	.byte	se_w109_rev	@ Reverb.

	.word	se_w109_grp

	.word	se_w109_1

	.end
