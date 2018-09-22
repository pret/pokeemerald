	.include "MPlayDef.s"

	.equ	se_select_grp, voicegroup127
	.equ	se_select_pri, 5
	.equ	se_select_rev, reverb_set+50
	.equ	se_select_mvl, 127
	.equ	se_select_key, 0
	.equ	se_select_tbs, 1
	.equ	se_select_exg, 0
	.equ	se_select_cmp, 1

	.section .rodata
	.global	se_select
	.align	2

@********************** Track  1 **********************@

se_select_1:
	.byte	KEYSH , se_select_key+0
	.byte	TEMPO , 300*se_select_tbs/2
	.byte		VOICE , 87
	.byte		VOL   , 80*se_select_mvl/mxv
	.byte		BEND  , c_v+13
	.byte		N03   , As5 , v068
	.byte	W03
	.byte		        Gn6 , v127
	.byte	W03
	.byte		        Gn6 , v068
	.byte	W03
	.byte		        Gn6 , v127
	.byte	W03
	.byte		VOICE , 88
	.byte		N06   , Gn6 , v068
	.byte	W06
	.byte	FINE

@******************************************************@
	.align	2

se_select:
	.byte	1	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_select_pri	@ Priority
	.byte	se_select_rev	@ Reverb.

	.word	se_select_grp

	.word	se_select_1

	.end
