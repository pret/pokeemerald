	.include "MPlayDef.s"

	.equ	se_w145_grp, voicegroup128
	.equ	se_w145_pri, 4
	.equ	se_w145_rev, reverb_set+50
	.equ	se_w145_mvl, 127
	.equ	se_w145_key, 0
	.equ	se_w145_tbs, 1
	.equ	se_w145_exg, 0
	.equ	se_w145_cmp, 1

	.section .rodata
	.global	se_w145
	.align	2

@********************** Track  1 **********************@

se_w145_1:
	.byte	KEYSH , se_w145_key+0
	.byte	TEMPO , 220*se_w145_tbs/2
	.byte		VOICE , 23
	.byte		VOL   , 95*se_w145_mvl/mxv
	.byte		BENDR , 12
	.byte		PAN   , c_v+0
	.byte		BEND  , c_v+0
	.byte		N09   , Cn3 , v127
	.byte	W03
	.byte		PAN   , c_v-16
	.byte		BEND  , c_v+6
	.byte	W01
	.byte		        c_v+16
	.byte	W02
	.byte		PAN   , c_v+16
	.byte		BEND  , c_v+37
	.byte	W01
	.byte		        c_v+48
	.byte	W02
	.byte		PAN   , c_v+0
	.byte		BEND  , c_v-1
	.byte		N03   , En3 
	.byte	W15
	.byte	FINE

@******************************************************@
	.align	2

se_w145:
	.byte	1	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_w145_pri	@ Priority
	.byte	se_w145_rev	@ Reverb.

	.word	se_w145_grp

	.word	se_w145_1

	.end
