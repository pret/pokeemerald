	.include "MPlayDef.s"

	.equ	se_tk_warpout_grp, voicegroup127
	.equ	se_tk_warpout_pri, 4
	.equ	se_tk_warpout_rev, reverb_set+50
	.equ	se_tk_warpout_mvl, 127
	.equ	se_tk_warpout_key, 0
	.equ	se_tk_warpout_tbs, 1
	.equ	se_tk_warpout_exg, 0
	.equ	se_tk_warpout_cmp, 1

	.section .rodata
	.global	se_tk_warpout
	.align	2

@********************** Track  1 **********************@

se_tk_warpout_1:
	.byte	KEYSH , se_tk_warpout_key+0
	.byte	TEMPO , 110*se_tk_warpout_tbs/2
	.byte		VOICE , 93
	.byte		XCMD  , xIECV , 9
	.byte		        xIECL , 8
	.byte		VOL   , 90*se_tk_warpout_mvl/mxv
	.byte		N06   , En5 , v064
	.byte	W03
	.byte	W03
	.byte		N03   , En5 , v016
	.byte	W03
	.byte		N06   , En5 , v088
	.byte	W03
	.byte	W03
	.byte		N03   , En5 , v016
	.byte	W03
	.byte		N06   , En5 , v112
	.byte	W03
	.byte	W03
	.byte		N03   , En5 , v016
	.byte	W03
	.byte		N06   , En5 , v127
	.byte	W03
	.byte	W03
	.byte		N03   , En5 , v016
	.byte	W03
	.byte	FINE

@******************************************************@
	.align	2

se_tk_warpout:
	.byte	1	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_tk_warpout_pri	@ Priority
	.byte	se_tk_warpout_rev	@ Reverb.

	.word	se_tk_warpout_grp

	.word	se_tk_warpout_1

	.end
