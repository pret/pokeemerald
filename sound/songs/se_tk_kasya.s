	.include "MPlayDef.s"

	.equ	se_tk_kasya_grp, voicegroup_869D0F4
	.equ	se_tk_kasya_pri, 4
	.equ	se_tk_kasya_rev, reverb_set+50
	.equ	se_tk_kasya_mvl, 127
	.equ	se_tk_kasya_key, 0
	.equ	se_tk_kasya_tbs, 1
	.equ	se_tk_kasya_exg, 0
	.equ	se_tk_kasya_cmp, 1

	.section .rodata
	.global	se_tk_kasya
	.align	2

@********************** Track  1 **********************@

se_tk_kasya_1:
	.byte	KEYSH , se_tk_kasya_key+0
	.byte	TEMPO , 150*se_tk_kasya_tbs/2
	.byte		VOICE , 126
	.byte		VOL   , 110*se_tk_kasya_mvl/mxv
	.byte		N01   , Gs3 , v127
	.byte	W01
	.byte		        Cn4 , v068
	.byte	W02
	.byte	W02
	.byte		N03   , Gs4 , v127
	.byte	W01
	.byte	W03
	.byte	FINE

@******************************************************@
	.align	2

se_tk_kasya:
	.byte	1	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_tk_kasya_pri	@ Priority
	.byte	se_tk_kasya_rev	@ Reverb.

	.word	se_tk_kasya_grp

	.word	se_tk_kasya_1

	.end
