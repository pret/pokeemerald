	.include "MPlayDef.s"

	.equ	se_kon3_grp, voicegroup128
	.equ	se_kon3_pri, 4
	.equ	se_kon3_rev, reverb_set+50
	.equ	se_kon3_mvl, 127
	.equ	se_kon3_key, 0
	.equ	se_kon3_tbs, 1
	.equ	se_kon3_exg, 0
	.equ	se_kon3_cmp, 1

	.section .rodata
	.global	se_kon3
	.align	2

@********************** Track  1 **********************@

se_kon3_1:
	.byte	KEYSH , se_kon3_key+0
	.byte	TEMPO , 150*se_kon3_tbs/2
	.byte		VOICE , 16
	.byte		VOL   , 100*se_kon3_mvl/mxv
	.byte		BEND  , c_v+1
	.byte		N12   , Fn4 , v088
	.byte	W12
	.byte	FINE

@********************** Track  2 **********************@

se_kon3_2:
	.byte	KEYSH , se_kon3_key+0
	.byte		VOICE , 17
	.byte		VOL   , 100*se_kon3_mvl/mxv
	.byte		BEND  , c_v+0
	.byte		N09   , Fn4 , v072
	.byte	W12
	.byte	FINE

@******************************************************@
	.align	2

se_kon3:
	.byte	2	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_kon3_pri	@ Priority
	.byte	se_kon3_rev	@ Reverb.

	.word	se_kon3_grp

	.word	se_kon3_1
	.word	se_kon3_2

	.end
