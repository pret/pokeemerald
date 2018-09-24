	.include "MPlayDef.s"

	.equ	se_tk_warpin_grp, voicegroup127
	.equ	se_tk_warpin_pri, 4
	.equ	se_tk_warpin_rev, reverb_set+50
	.equ	se_tk_warpin_mvl, 127
	.equ	se_tk_warpin_key, 0
	.equ	se_tk_warpin_tbs, 1
	.equ	se_tk_warpin_exg, 0
	.equ	se_tk_warpin_cmp, 1

	.section .rodata
	.global	se_tk_warpin
	.align	2

@********************** Track  1 **********************@

se_tk_warpin_1:
	.byte	KEYSH , se_tk_warpin_key+0
	.byte	TEMPO , 110*se_tk_warpin_tbs/2
	.byte		VOICE , 90
	.byte		VOL   , 90*se_tk_warpin_mvl/mxv
	.byte		N06   , En4 , v127
	.byte	W03
	.byte	W03
	.byte		N03   , En4 , v016
	.byte	W03
	.byte		N06   , En4 , v112
	.byte	W03
	.byte	W03
	.byte		N03   , En4 , v016
	.byte	W03
	.byte		N06   , En4 , v088
	.byte	W03
	.byte	W03
	.byte		N03   , En4 , v016
	.byte	W03
	.byte		N06   , En4 , v064
	.byte	W03
	.byte	W03
	.byte	FINE

@******************************************************@
	.align	2

se_tk_warpin:
	.byte	1	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_tk_warpin_pri	@ Priority
	.byte	se_tk_warpin_rev	@ Reverb.

	.word	se_tk_warpin_grp

	.word	se_tk_warpin_1

	.end
