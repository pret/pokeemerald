	.include "MPlayDef.s"

	.equ	se_win_open_grp, voicegroup_rs_sfx_1
	.equ	se_win_open_pri, 5
	.equ	se_win_open_rev, reverb_set+50
	.equ	se_win_open_mvl, 127
	.equ	se_win_open_key, 0
	.equ	se_win_open_tbs, 1
	.equ	se_win_open_exg, 0
	.equ	se_win_open_cmp, 1

	.section .rodata
	.global	se_win_open
	.align	2

@********************** Track  1 **********************@

se_win_open_1:
	.byte	KEYSH , se_win_open_key+0
	.byte	TEMPO , 220*se_win_open_tbs/2
	.byte		VOICE , 127
	.byte		VOL   , 110*se_win_open_mvl/mxv
	.byte		N03   , Ds3 , v127
	.byte	W03
	.byte		N15   , Gn4
	.byte	W21
	.byte	FINE

@******************************************************@
	.align	2

se_win_open:
	.byte	1	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_win_open_pri	@ Priority
	.byte	se_win_open_rev	@ Reverb.

	.word	se_win_open_grp

	.word	se_win_open_1

	.end
